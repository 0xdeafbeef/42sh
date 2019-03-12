# SHELL

# Minishell
___
### MAIN:
* executable - *minishell*
* Manage errors without errno
* Correctly deal with the PATH and the environment
* Expansions ~ and $

| Allowed Functions         | Built-ins           | Bonuses  |
| :------------------------:|:-------------:| :-----:|
| malloc,free               | echo | Auto completition |
| access                    | cd      | Signal Handler |
| open,close,read,write     | env      | Separation with ";" |
| opendir,readdir,closedir  | setenv | Management of execution rights in the PATH |
| getcwd,chdir              | unsetenv      |  |
| stat,lstat,fstat          | exit    |    |
| fork,execve               |  | |
| wait,waitpid,wait3,wait4  |       |  |
| signal,kill               |   |  |
| exit                      |    |   |

# 21sh
___
Here are couple of key words that we must properly understand: “lexicalanalysis”, “lexer”, “syntactic analysis”, “parser”, “semantics analysis”,“interpreter”, andof course “abstract syntax tree” (or “AST”)

## MAIN:
*   Builtin - type
*   Line editing используя билиотеку termcaps
*   Ctrl+C Ctrl+D для процессов и line edition
*   The ";" command line separator
*   Pipes |
*   "<", ">", "<<", ">>"
*   Обработка файловых дескрипторов &> 2>
*   Изменение строки где находится курсор
*   Стрелка вверх и вниз чтобы перемещаться по истории
*   Вырезать, копировать, вставлять часть строки
*   ctrl+LEFT, ctrl+RIGHT вперед по слову или назад
*   К началу или к концу строки - Home, End
*   Писать и редактировать строку на нескольких строчках (ctrl+UP, ctrl+DOWN чтобы перемещаться по строкам)
*   Обработка кавычек
## BONUSES:
* Поиск по истории, используя ctrl+R
* Сделать hash таблицу для бинарных файлов
* Простой или advanced комплит, используя tab.
* Emacs и/или Vimbinding режим свободно активирующийся или деактивирующийся.
* Подсветка синтаксиса свободно активирующаяся или деактивирующаяся.

|Allowed functions|
|:---------------:|
|malloc,free|
access|
open,close,read,write|
opendir,readdir,closedir|
getcwd,chdir|
stat,lstat,fstat|
fork,execve|
wait,waitpid,wait3,wait4|
signal,kill|
exit|
pipe|
dup,dup2|
isatty,ttyname,ttyslot|
ioctl|
getenv|
tcsetattr,tcgetattr|
tgetent|
tgetflag|
tgetnum|
tgetstr|
tgoto|
tputs|

# 42sh
___
## MAIN:
*   Mониторинг переменных. (Don’t care about read-only variables)
    *   Создание переменных в зависимости от синтаксиса:имя=значение
    *   Отправить переменную в env с помощью built-in export
    *   Возможность отобразить переменные shell с помощью built-in set(без опций).
    *   Отмена нутренних и env переменныех с помощью builtin unset(без опций).
    *   Создание Env переменных для уникальных команд: HOME=/tmp cd.
    *   Простое раскрытие параметров в зависимости от синтаксиса ${}
    *   Доступ к exit коду предыдущей команды с помощью ${?}
* Работа с job с помощью jobs, fg, bf и оператором &
* Корректная обработка всех сигналов
* Все Built-in должны иметь опции из POSIX стандарта, кроме set, unset

## MODULE: (6)
* Inhibitors ' " and \
* Pattern matching (globing) *, ?, [], ! and the caracters intervals with \
* Title expansions and additional parameters format:
    ``` shell
    $ animal=cat
    $ echo $animals
                                    # No such variable as “animals”.
    $ echo ${animal}s
    cats
    $ echo $animal_food
                                    # No such variable as “animal_food”.
    $ echo ${animal}_food
    cat_food
    ```
    * ~
    * ${parameter:-word}
    * ${parameter:=word}
    * ${parameter:?word}
    * ${parameter:+word}
    * ${#parameter}
    * ${parameter%}
    * ${parameter%%}
    * ${parameter#}
    * ${parameter##}
* Control groups and sub-shells:(),{};
* Control substitution:$() - Command substitution
    ``` shell
    $ ls -ld $(date +%B).txt
    -rwxr-xr-x  1 Noob Noob    867 Jul  2 11:09 July.txt
    ```
* Arithmetic expansion:(()) Only these operators:
    * Incrementality, decrementing++ --
    * Addition, Soustraction+ -
    * Multiplication, division, modulo* / %
    * Comparison<= >= < >
    * Equality, differencies == !=
    * AND/OR logical && ||
    [Read More](http://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap01.html#tag_17_01_02_01)
* Process substitution:,()),<(),>()
    ``` shell
    diff <(sort file1) <(sort file2)
    ```
* Полная обработка истории:
    * Авто раскрытие:
        * !! - последняя использованная команда
        * !word - поиск последней команды по слову
        * !number - команда по номеру
        * !-number команда по номеру с конца
    * Сохранять историю в файл, чтобы юзать в разных сессиях
    * Built-in fc (все POSIX опции)
    * Инкреметный поиск в истории с помощью CTRL-R
* Contextual autocompletition (Нормальный комплит), если пишем echo ${$ - то будет дополнять только переменные
* Редактирование строки с помощью Vim и Emacs
    * Включать с помощью флага -o build-in set
    * Vi:#,  ,v,j,k,l,h,w,W,e E b B ˆ $ 0 |,f,F,;,,,a,A,i,I,r,R,c,C,S,x,X,d,D,y,y,Y,p,P,u,U.
    * Readline:C-b,C-f,C-p,C-n,C-_,C-t,A-t
    [VI Keybindings](http://pubs.opengroup.org/onlinepubs/9699919799/utilities/sh.html)
    [Readline](http://www.bigsmoke.us/readline/shortcuts)
* Alias и unalias
* Hash таблица и Builtin hash чтобы работать с ней
* test Built in с поддержкой следующих флагов:
    * texttt-b,-c,-d,-e,-f,-g,-L,-p,-r,-S,-s,-u,-w,-x,-z,=,!=,-eq,-ne,-ge,-lt,-le,!
    * возможность простого операнда без оператора

## BONUSES:
*   Shell Script (while,for,if.case,function, etc.)
*   Автокомплит для builtin параметров
*   Шелл совместим с  [POSIX](http://pubs.opengroup.org/onlinepubs/9699919799/) Standard

## IMPORTANT:
*   Не должно быть тернарников кадый 3 строки
*   Нормальные названия для функция (не должно быть ft_parse1,ft_parse2, и т.д.)
*   Это применимо и к переменным
*   Использовать const везде где можно
*   Гит история и нормальные коммиты
*   Автоматизированные тесты










