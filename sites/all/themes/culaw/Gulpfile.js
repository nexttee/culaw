  var gulp = require('gulp');
  var eslint = require('gulp-eslint');
  var stylelint = require('gulp-stylelint').default;
  var sass = require('gulp-sass');
  var sourcemaps = require('gulp-sourcemaps');
  var autoprefixer = require('gulp-autoprefixer');
  var babel = require('gulp-babel');
  var uglify = require('gulp-uglify');
  var imagemin = require('gulp-imagemin');
  var consoleReporter = require('gulp-stylelint-console-reporter').default;
  var browserSync = require("browser-sync").create();
  var reload = browserSync.reload;

  var config = {
    sass: {
      input: 'sass/**/*.scss',
      output: './build',
      options: {
        dev: {
          errLogToConsole: true,
          outputStyle: 'expanded'
        },
        prod: {
          outputStyle: 'compressed'
        }
      }
    },
    js: {
      input: 'js/**/*.js',
      output: './build',
    },
    babel: {
      input: 'js/**/*.es6.js',
      output: './build',
      options: {
        presets: ['es2015']
      }
    },
    img: {
      input: 'img/**/*.*',
      output: './build/img',
      options: {
        optimizationLevel: 3,
        progressive: true,
        interlaced: true
      }
    },
    autoprefixer: {
      browsers: ['last 2 versions', '> 5%']
    },
    browserSync: {
      url: process.env.BSURL
    }
  };

gulp.task('sass:dev', function() {
  return gulp.src([config.sass.input])
  .pipe(sourcemaps.init())
  .pipe(sass(config.sass.options.dev).on('error', sass.logError))
  .pipe(sourcemaps.write(undefined, {sourceRoot: null}))
  .pipe(autoprefixer(config.autoprefixer))
  .pipe(gulp.dest(config.sass.output))
  .pipe(reload({stream: true}));
});

gulp.task('sass:prod', function() {
  return gulp.src([config.sass.input])
  .pipe(sass(config.sass.options.prod).on('error', sass.logError))
  .pipe(autoprefixer())
  .pipe(gulp.dest(config.sass.output));
});

gulp.task('js:dev', function() {
  return gulp.src([config.js.input])
  .pipe(sourcemaps.init())
  .pipe(gulp.dest(config.js.output))
  .pipe(reload({stream: true}));
});

gulp.task('js:prod', function() {
  return gulp.src([config.js.input])
  .pipe(uglify())
  .pipe(gulp.dest(config.js.output));
});

gulp.task('babel:dev', function() {
  return gulp.src([config.babel.input])
  .pipe(sourcemaps.init())
  .pipe(babel(config.babel.options))
  .pipe(gulp.dest(config.babel.output))
  .pipe(reload({stream: true}));
});

gulp.task('babel:prod', function() {
  return gulp.src([config.babel.input])
  .pipe(babel(config.babel.options))
  .pipe(uglify())
  .pipe(gulp.dest(config.babel.output));
});

gulp.task('images', function() {
  return gulp.src([config.img.input])
  .pipe(imagemin(config.img.options));
});

gulp.task('prod', function() {
  gulp.start(['sass:prod', 'js:prod', 'babel:prod', 'images']);
});

gulp.task('watch', function() {
  if (process.env.BSURL) {
    browserSync.init({
        proxy: config.browserSync.url
    });
  }
});
