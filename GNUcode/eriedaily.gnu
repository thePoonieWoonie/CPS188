set title 'Lake Erie Daily Average Ice Concentration'
set xlabel 'Days'
set ylabel 'Ice Concentration (%)'
set xtics 10
set ytics 3
plot 'eriedailyavg.txt' using 1:2 title 'Ice concentration' with l 