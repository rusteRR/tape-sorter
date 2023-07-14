## Коротко о реализации

Идея в том, чтобы разбить нашу большую ленту на ленты размера `M` и отсортировать каждую ленту.
После этого установить указатели на первые элементы каждой вспомогательной ленты и добавить их в кучу (`set`), затем 
просто доставать минимум и писать его на выходную ленту

## Расширяемость

Предоставляются 2 интерфейса `tape` и `tape_fabric_interface`. Реализовав эти интерфейсы - 
вы получаете рабочий алгоритм для совершенно любой имплементации ленты.

`tape_fabric_interface` - интерфейс, который предоставляет возможность пользователю получить в пользование
доступную ленту. В текущей тестовой реализации - это просто создание файла. В действительности же это может
быть какой-то вызов, который предоставляет реальную ленту.

## Тесты

Написаны стресс-тесты, написать тест для `N = 1e8`, чтобы его запустить - достаточно объявить макрос препроцессора
`HUGE_TEST`

## Формат `config` файла

`<M> <R> <W> <M>`

- `M` - ограничение из условия на количество чисел в оперативной памяти
- `R` - задержка по чтению с ленты
- `W` - задержка по записи на ленту
- `M` - задержка по свдигу ленты