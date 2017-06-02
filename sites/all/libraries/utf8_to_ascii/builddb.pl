#!/usr/bin/perl -w
# Lower oder perl...
use strict;
use Getopt::Long qw(:config gnu_getopt);
use Pod::Usage;
use Carp;
use Cwd 'realpath';
use IO::File;

my $DEBUG = 0;
my $NOLINT = 0;

GetOptions (
    'h' => sub {pod2usage(-exitstatus => 2, -section=>"SYNOPSIS");},
    'help' => sub {pod2usage(-exitstatus => 0, -verbose => 2);},
    'd|debug' => \$DEBUG,
    'n|nolint' => \$NOLINT
    ) or pod2usage(-exitstatus => 2, -section=>"SYNOPSIS");


if ( !defined $ARGV[0] ) {
    pod2usage(
        -exitstatus => 2,
        -section=>"SYNOPSIS",
        -msg => "Source directory required!"
        );
}
my $SOURCEDIR = realpath($ARGV[0]);
if ( !-e $SOURCEDIR || !-d $SOURCEDIR || !-e $SOURCEDIR.'/x00.pm' ) {
    pod2usage(
        -exitstatus => 2,
        -section=>"SYNOPSIS",
        -msg => "$SOURCEDIR is not a valid location - need the Text::Unidecode bank dir"
        );
}

if ( !defined $ARGV[1] ) {
    pod2usage(
        -exitstatus => 2,
        -section=>"SYNOPSIS",
        -msg => "Target directory required!"
        );
}
my $TARGETDIR = realpath($ARGV[1]);
if ( !-e $TARGETDIR || !-d $TARGETDIR ) {
    pod2usage(
        -exitstatus => 2,
        -section=>"SYNOPSIS",
        -msg => "Invalid target directory $TARGETDIR"
        );
}

my @BANKS = (0 .. 255);
my @Char;
my @Keys;
my @Outfiles;

foreach my $bank ( @BANKS ) {
    my $bankfile = $SOURCEDIR . '/' .sprintf('x%02x.pm', $bank);
    
    if ( $DEBUG ) {
        print "Looking for $bankfile\n";
    }
    
    if ( !-e $bankfile ) {
        if ( $DEBUG ) {
            print "Not found: $bankfile - skipping\n";
        }
        next;
    }
    
    if ( $DEBUG ) {
        print "Found: $bankfile - processing\n";
    }
    
    my $sh = new IO::File "< $bankfile";
    my $content = join("\n",$sh->getlines);
    $content =~ s/Text::Unidecode:://;
    if ( $content =~ m/Char(\[0x.{2}\])/ ) {
        push(@Keys, $1);
    } else {
        $sh->close;
        croak("Error extacting key");
    }
    push(@Outfiles, sprintf('x%02x.php', $bank));
    eval $content;
    $sh->close;
}

if ( $DEBUG ) {
    print "Finished processing source files. Writing PHP scripts\n";
}

# Yes this could have been done earlier but this makes thinking easier in lower order Perl
foreach my $charbank ( @Char ) {
    my $outfile = shift(@Outfiles);
    if ( !$outfile ) {
        next;
    }
    if ( $DEBUG ) {
        print "Writing to $TARGETDIR/$outfile\n";
    }
    
    my $th = new IO::File "> $TARGETDIR/$outfile" or
        croak ("Cant open $TARGETDIR/$outfile");
    
    print $th '<?php'."\n";
    print $th "\$UTF8_TO_ASCII".shift(@Keys)." = array(\n";
    
    foreach my $char ( @{$charbank} ) {
        $char =~ s/\\/\\\\/;
        if ( $char !~ m/'/ ) {
            print $th "'$char',";
        } else {
            $char =~s/"/0x22/;
            print $th '"'.$char.'"'.",";
        }
    }
    print $th "\n);\n";
    
    if ( !$NOLINT ) {
        system("php -l $TARGETDIR/$outfile > /dev/null") == 0
            or croak("$outfile failed PHP lint check");
        if ( $DEBUG ) {
            print "Output PHP syntax OK\n";
        }
    }
    
    if ( $DEBUG ) {
        print "$TARGETDIR/$outfile written successfully\n";
    }
    $th->close;
}

if ( $DEBUG ) {
    print "Done\n";
}

exit(0);

__END__

=head1 SYNOPSIS

    $ builddb.pl <path_to_unidecode_banks> <output_dir>

=head2 Options:

=over 4

=item -h, -?

summary help

=item --help

full help description

=item -d, --debug

Explains what it's doing

=item -n, --nolint

Disable check (by PHP) on output source file.

=back
  
=head1 DESCRIPTION

Builds a UTF-8 character to ASCII transliteration database from the Text::Unidecode database, the output being
PHP versions of the same.

Note this script takes the brute force approach - it doesn't attempt to C<require> the Text::Unidecode
files but rather evals them after applying some regexes - seemed like the easiest way after some playing.

Also, by default, it attempts to check the syntax of the output PHP scripts using C<php -l filename.php>.
This assumes you have the command PHP version installed and in your path.

=head2 EXAMPLES

    $ unidecode2php.pl /tmp/Text-Unidecode-0.04/lib/Text/Unidecode ./db

=head1 CREDITS

Many thanks to Sean M. Burke for the outstanding job on Text::Unidecode

=head1 SEE

L<http://search.cpan.org/~sburke/Text-Unidecode-0.04/>,
L<Text::Unicode>
L<http://interglacial.com/~sburke/>

=head1 LICENSE

The Perl Artistic License

=cut

