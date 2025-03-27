set title 'Lake Ontario Daily Average Ice Concentration'
set xlabel 'Days'
set ylabel 'Ice Concentration (%)'
set xtics 10
set ytics 10
plot 'ontario8.txt' using 1:2 title '2021-2022' with l linecolor 'purple', \
'ontario8.txt' using 1:3 title '2022-2023' with l linecolor 'red', \
'ontario8.txt' using 1:4 title '2023-2024' with l linecolor 'blue'