set term postscript eps color colortext font 'Times-Roman, 20'
set output "plot/".ARG1."/".ARG1.".eps"

set key left top

set lmargin at screen 0.15
set ytics 
set yrange [0:*]

set ytics 
set y2range [0:*]

set x2tics 


set grid
set xlabel "Splint - Time (ms)" font ', 22'
set x2label "SoftBound+CETS - Time (ms)" font ', 22'
set ylabel "Memory (KB)" offset 0,0 font ', 22'

plot "plot/".ARG1."/".ARG1.".splint" using ($2/1024) with lines axes x1y1 lw 4 title "Splint", \
     "plot/".ARG1."/".ARG1.".cets" using ($2/1024) with lines axes x2y1 lw 4 title "SoftBound+CETS"