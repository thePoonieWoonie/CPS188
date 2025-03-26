set title 'Lake Huron Daily Average Ice Concentration'
set xlabel 'Days'
set ylabel 'Ice Concentration (%)'
set xtics 10
set ytics 2
plot 'hurondailyavg.txt' using 1:2 title 'Ice concentration' with l 