
```
cpp -v
```

探しにいく


```
find /usr/local/include/ -name stdio.h

```



なかった


```
taish ~
find /usr/include/ -name stdio.h
/usr/include//c++/4.2.1/tr1/stdio.h
/usr/include//stdio.h
```

見つけた。


```
make -p | less
```

コマンドの説明などを表示する。


##参考

http://qiita.com/awakia/items/e0ceeabd8faf95020cbd

http://www.02.246.ne.jp/~torutk/cxx/automake/automake.html
