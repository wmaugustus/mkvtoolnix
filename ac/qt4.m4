dnl
dnl Check for Qt 4 or newer
dnl

AC_ARG_ENABLE([qt],
  AC_HELP_STRING([--enable-qt],[compile the Qt version of the GUIs (no)]))

qt_min_ver=4.0.0

if test x"$enable_qt" = "xyes" -a \
  '(' x"$enable_gui" = x"yes" -o x"$enable_gui" = "x" ')'; then
  dnl Find moc.
  AC_ARG_WITH(moc,
    AC_HELP_STRING([--with-moc=prog],[use prog instead of looking for moc]),
    [ MOC="$with_moc" ],)
  if ! test -z "$MOC"; then
    AC_MSG_CHECKING(for moc)
    AC_MSG_RESULT(using supplied $MOC)
  else
    AC_PATH_PROG(MOC, moc-qt4,, $PATH)
    if test -z "$MOC"; then
      AC_PATH_PROG(MOC, moc,, $PATH)
    fi
  fi
  if test -z "$MOC" -o ! -x "$MOC"; then
    echo "*** The 'moc' binary was not found or is not executable."
    exit 1
  fi

  dnl Check its version.
  AC_MSG_CHECKING(for the Qt version $MOC uses)
  moc_ver=`"$MOC" -v 2>&1 | sed -e 's:.*Qt ::' -e 's:[[^0-9\.]]::g'`
  if test -z "moc_ver"; then
    AC_MSG_RESULT(unknown; please contact the author)
  elif ! check_version $qt_min_ver $moc_ver; then
    AC_MSG_RESULT(too old: $moc_ver)
  else
    AC_MSG_RESULT($moc_ver)
    moc_found=1
  fi

  AC_ARG_WITH(uic,
    AC_HELP_STRING([--with-uic=prog],[use prog instead of looking for uic]),
    [ UIC="$with_uic" ],)

  if test x"$moc_found" = "x1"; then
    if ! test -z "$UIC"; then
      AC_MSG_CHECKING(for uic)
      AC_MSG_RESULT(using supplied $UIC)
    else
      AC_PATH_PROG(UIC, uic-qt4,, $PATH)
      if test -z "$UIC"; then
        AC_PATH_PROG(UIC, uic,, $PATH)
      fi
    fi
    if test -z "$UIC" -o ! -x "$UIC"; then
      echo "*** The 'uic' binary was not found or is not executable."
      exit 1
    fi

    dnl Check its version.
    AC_MSG_CHECKING(for the Qt version $UIC uses)
    uic_ver=`"$UIC" -v 2>&1 | sed -e 's:.*Qt ::' -e 's:[[^0-9\.]]::g'`
    if test -z "uic_ver"; then
      AC_MSG_RESULT(unknown; please contact the author)
    elif ! check_version $qt_min_ver $uic_ver; then
      AC_MSG_RESULT(too old: $uic_ver)
    else
      AC_MSG_RESULT($uic_ver)
      uic_found=1
    fi
  fi

  AC_MSG_CHECKING(for Qt $qt_min_ver or newer)
  if test x"$moc_found" != "x1"; then
    AC_MSG_RESULT(no: moc not found)
  elif test x"$uic_found" != "x1"; then
    AC_MSG_RESULT(no: uic not found)
  elif ! pkg-config QtGui --atleast-version=$qt_min_ver || \
     ! pkg-config QtCore --atleast-version=$qt_min_ver ; then
    AC_MSG_RESULT(no: pkg-config says "too old")
  else
    dnl Try compiling and linking an application.
    QT_CFLAGS="`pkg-config QtCore --cflags` `pkg-config QtGui --cflags`"
    QT_LIBS="`pkg-config QtGui --libs`"

    AC_LANG_PUSH(C++)
    AC_CACHE_VAL(am_cv_qt_compilation, [
      run_qt_test=1
      while true; do
        ac_save_CXXFLAGS="$CXXFLAGS"
        ac_save_LIBS="$LIBS"
        CXXFLAGS="$CXXFLAGS $QT_CFLAGS"
        LIBS="$LDFLAGS $QT_LIBS"
        unset ac_cv_qt_compilation

        AC_TRY_LINK([
#include <QtCore>
class Config : public QCoreApplication {
public:
Config(int &argc, char **argv);
};
Config::Config(int &argc, char **argv)
: QCoreApplication(argc,argv) {setApplicationName("config");}
          ], [
int ai = 0;
char **ac = 0;
Config app(ai,ac);
qWarning(qPrintable(app.applicationName()));
return 0;
          ], [ am_cv_qt_compilation=1 ], [ am_cv_qt_compilation=0 ])

        CXXFLAGS="$ac_save_CXXFLAGS"
        LIBS="$ac_save_LIBS"

        if test x"$am_cv_qt_compilation" = x1; then
          break

        elif test x"$run_qt_test" = "x1"; then
          dnl On some systems (notably OpenSuSE 10.0) the pkg-config for the
          dnl --cflags don't include the QtCore and QtGui subdirectories.
          dnl Add them now.
          set - $QT_CFLAGS
          while test ! -z "$1" ; do
            case "$1" in
              -I*)
                QT_CFLAGS="$QT_CFLAGS $1/QtCore $1/QtGui"
                ;;
            esac
            shift
          done
          run_qt_test=2

        elif test x"$run_qt_test" = "x2"; then
          QT_CFLAGS="$QT_CFLAGS -I/usr/include/QtCore -I/usr/include/QtGui -I/usr/local/include/QtCore -I/usr/local/include/QtGui"
          run_qt_test=3

        else
          break

        fi
      done
      ])
    AC_LANG_POP()

    if test x"$am_cv_qt_compilation" = x1; then
     AC_DEFINE(HAVE_QT, 1, [Define if Qt is present])
     have_qt=yes
     USE_QT=yes
     opt_features_yes="$opt_features_yes\n   * GUIs (Qt version)"
     AC_MSG_RESULT(yes)
    else
      AC_MSG_RESULT(no: test program could not be compiled)
    fi
  fi
fi

if test x"$have_qt" != "xyes" ; then
  opt_features_no="$opt_features_no\n   * GUIs (Qt version)"
fi

AC_SUBST(MOC)
AC_SUBST(UIC)
AC_SUBST(QT_CFLAGS)
AC_SUBST(QT_LIBS)
AC_SUBST(USE_QT)
