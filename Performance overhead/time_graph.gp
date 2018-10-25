
set term postscript eps color colortext font 'Times-Roman, 20'
set output "time.eps"


set key
set offset 0.5, 0.5, 0, 0
set ylabel 'Seconds' font ', 22'
set boxwidth 1.5
set style histogram cluster gap 4


set termopt enhanced
set datafile separator ","
set grid ytics xtics
set xtics font ', 22'
set ytics font ', 22'
set style data histogram
set style fill solid 0.75 border -1


set style line 1 lc rgb 'black' lt 1 lw 1
set style line 2 lc rgb 'black' lt 1 lw 1
set style line 3 lc rgb 'red' lt 1 lw 1

set style data histogram
set style fill pattern border -1


plot 'time.csv' u 2:xticlabels(1) title columnheader fs pattern 3 ls 1  \
           , '' u 3:xticlabels(1) title columnheader fs pattern 5 ls 2  \


