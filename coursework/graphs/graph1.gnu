set termoption enhanced
set terminal svg size 1920, 1080 font "Arial, 16"
set output "graph1.svg"

set style line 1 lc rgb "0x00ffff" lt 1 lw 4 pt 9 ps 1
set style line 2 lc rgb "0x006400" lt 1 lw 4 pt 7 ps 1

set border lw 2
set grid
set key top left

set logscale y

set xlabel "Elements in array"
set ylabel "Execution time, sec" rotate by 90
set xtics 5000
set mxtics
set format x "%6.0f"
set format y "%.2f"

plot "sort1.dat" using 1:3 title "Bubble Sort" with linespoints ls 2, \
"sort1.dat" using 1:2 title "Quick Sort" with linespoints ls 3