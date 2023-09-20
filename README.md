# deikstra_algo
При выполнении данной работы было выяснено, что алгоритм Дейкстры (на очереди и на векторе) работает в десятки раз быстрее остальных алгоритмов уже на первых итерациях цикла. Этот разрыв становится более заметным на последних итерациях, где затраченное время отличается более, чем в сотни и тысячи раз.

Наиболее сильно это проявляется на разреженных графах из-за специфики их генерации. Разреженные графы могут содержать относительно малое количество ребер при большом количестве вершин. Алгоритм Дейкстра более выборочно проходится по ребрам и вершинам, в сравнении с остальными, представленными в работе, алгоритмами. Из-за чего появляется разница в внешнем виде графиков (на алгоритме Дейкстра они выглядят более нестабильными) на графах такого рода.

По выполнению работы можно прийти к выводу, что при поиске наикратчайших путей в графах стоит прибегать к использованию алгоритма Дейкстра, нежели остальных, настолько, насколько это возможно.

В работе было реализовано:

  1) Генераторы полных\соединенных\разреженных графов
  2) Алгоритмы поиска наикратчайшего пути в графе таких как:
    2.1) Алгоритм Дейкстра через очередь с приоритетом
    2.2) Алгоритм Дейкстра через вектор
    2.3) Алгоритм Флойда-Уоршелла
    2.4) Алгоритм Форда-Беллмана
  3) Таймеры для замерения времени работы алгоритмов
  4) Рекордеры для записи усредненного времени работы алгоритмов
  5) Отдельный метод для записи получившихся результатов в .csv файл