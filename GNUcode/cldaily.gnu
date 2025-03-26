set title 'Lake St Clair Daily Average Ice Concentration'
set xlabel 'Days'
set ylabel 'Ice Concentration (%)'
set xtics 10
set ytics 10
plot 'cldailyavg.txt' using 1:2 title 'Ice concentration' with l 