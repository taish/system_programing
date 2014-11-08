##automakeの流れ

###1. Makefile.amを記述
```
bin_PROGRAMS = myapp
myapp_SOURCES = mymain.c mysub1.c mysub2.c myapp.h
```


###2. autoscanコマンド
configure.scanができる

###3. configure.scanの名前をconfigure.acにする

configure.acを編集
1行目を編集
2行目を追加
```
AC_INIT(myapp, 1.0, kbystis@icloud.com)
AM_INIT_AUTOMAKE([foreign])
```

###4. autoheaderでconfig.h.inとautom4te.cachを作る
```
autoheader
taish ~/note/system_programming/3/kadai2 master
ls
Makefile.am	autom4te.cache/	config.h.in	myapp*		mymain.c	mysub1.c	mysub2.c
README.md	autoscan.log	configure.ac	myapp.h		mymain.o	mysub1.o	mysub2.o
```

###5. aclocal実行
```
ls -a
./		INSTALL		aclocal.m4	config.h.in	myapp*		mymain.o	mysub2.c
../		Makefile.am	autom4te.cache/	configure.ac	myapp.h		mysub1.c	mysub2.o
COPYING		README.md	autoscan.log	depcomp*	mymain.c	mysub1.o
```

###6. automake実行
```
automake --add-missing --copy
configure.ac:11: installing './compile'
configure.ac:6: installing './install-sh'
configure.ac:6: installing './missing'
taish ~/note/system_programming/3/kadai2 master
ls
COPYING		README.md	compile*	install-sh*	mymain.c	mysub2.c
INSTALL		aclocal.m4	config.h.in	missing*	mymain.o	mysub2.o
Makefile.am	autom4te.cache/	configure.ac	myapp*		mysub1.c
Makefile.in	autoscan.log	depcomp*	myapp.h		mysub1.o
```

###7. Makefile作成

```
./configure
checking for a BSD-compatible install... /usr/bin/install -c
checking whether build environment is sane... yes
checking for a thread-safe mkdir -p... ./install-sh -c -d
checking for gawk... no
checking for mawk... no
checking for nawk... no
checking for awk... awk
checking whether make sets $(MAKE)... yes
checking whether make supports nested variables... yes
checking for gcc... gcc
checking whether the C compiler works... yes
checking for C compiler default output file name... a.out
checking for suffix of executables...
checking whether we are cross compiling... no
checking for suffix of object files... o
checking whether we are using the GNU C compiler... yes
checking whether gcc accepts -g... yes
checking for gcc option to accept ISO C89... none needed
checking whether gcc understands -c and -o together... yes
checking for style of include used by make... GNU
checking dependency style of gcc... gcc3
checking that generated files are newer than configure... done
configure: creating ./config.status
config.status: creating Makefile
config.status: creating config.h
config.status: executing depfiles commands
```

###8. myapp実行
./myapp
main
mysub1
mysub2

##参考

http://qiita.com/awakia/items/e0ceeabd8faf95020cbd

http://www.02.246.ne.jp/~torutk/cxx/automake/automake.html
