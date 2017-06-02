<?php
if ( isset($_GET['out']) && $_GET['out'] == 'ascii' ) {
    header('Content-Type: text/html; charset=US-ASCII');
} else {
    header('Content-Type: text/html; charset=UTF-8');
}
require_once '../utf8_to_ascii.php';
$out = file_get_contents('data/utf8.txt');
if ( isset($_GET['out']) && $_GET['out'] == 'ascii' ) {
    $out = utf8_to_ascii($out);
}
?>
<html>
<head>
<title>US-ASCII transliterations of Unicode text</title>
</head>
<body>
<h1>US-ASCII transliterations of Unicode text</h1>
<p><a href="?out=utf-8">Before</a> | <a href="?out=ascii">After</a></p>
<pre>
<?php
print(htmlspecialchars($out));
?>
</pre>
</body>
</html>

