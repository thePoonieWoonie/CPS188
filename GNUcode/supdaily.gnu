set title 'Lake Superior Daily Average Ice Concentration'
set xlabel 'Days'
set ylabel 'Ice Concentration (%)'
set xtics 10
set ytics 1
plot 'supdailyavg.txt' using 1:2 title 'Ice concentration' with l 