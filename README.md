# Sortowanie
Introsort, MergeSort, QuickSort

  •	Sortowanie przez scalanie

Sortowanie przez scalanie wykorzystuje metodę „dziel i zwyciężaj”. Algorytm polega on na tym, że rekurencyjnie dzieli tablice na mniejsze, aż do uzyskania tablic jednoelementowych. Następnie tablice są scalane, aż utworzą posortowaną tablicę. Złożoność obliczeniowa algorytmu wynosi O(.


•	Quicksort

Quicksort wykorzystuje metodę „dziel i zwyciężaj”. Najpierw wybierany jest punkt odniesienia i tablica jest dzielona na 2 podtablice o elementach mniejszych i większych od punktu odniesienia. Dla tych tablic rekurencyjnie jest wykorzystywana metoda Quicksort aż do uzyskania samych tablic jednoelementowych, co jest równoważne z posortowaniem tablicy.  Złożoność obliczeniowa algorytmu wynosi O(, a w najgorszym wypadku, gdy za punkt odniesienia będziemy ciągle brali największy bądź najmniejszy element O(.


•	Sortowanie introspektywne

Sortowanie introspektywne stanowi połączenie Quicksorta i sortowania przez Kopcowanie. Na początku jest wyliczana głębokość rekurencji. Algorytm sortuje za pomocą Quicksorta dopóki ilość wywołań rekurencyjnych nie przekroczy wyliczonej głębokości rekurencji. Gdy to się stanie algorytm resztę tablicy sortuje za pomocą sortownia przez kopcowanie. Algorytm powstał po to, żeby uniknąć najgorszych przypadków Quicksorta, gdy ma on złożoność obliczeniową O(.
