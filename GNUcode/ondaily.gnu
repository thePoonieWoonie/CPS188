set title 'Lake Ontario Daily Average Ice Concentration'
set xlabel 'Days'
set ylabel 'Ice Concentration (%)'
set xtics 10
set ytics 1
plot 'ondailyavg.txt' using 1:2 title 'Ice concentration' with l 