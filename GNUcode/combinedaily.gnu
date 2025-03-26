set title 'Great Lakes Daily Average Ice Concentration'
set xlabel 'Days'
set ylabel 'Ice Concentration (%)'
set xtics 10
set ytics 10
plot 'combinedailyavg.txt' using 1:2 title 'Lake Superior' with l dt 2, \
'combinedailyavg.txt' using 1:3 title 'Lake Michigan' with p pt 0 linecolor 'red', \
'combinedailyavg.txt' using 1:4 title 'Lake Huron' with p ps 0.5, \
'combinedailyavg.txt' using 1:5 title 'Lake Erie' with p pt 12 ps 0.3 linecolor 'black', \
'combinedailyavg.txt' using 1:6 title 'Lake Ontario' with l linecolor 'cyan', \
'combinedailyavg.txt' using 1:7 title 'Lake St Clair' with lp ps 0.5 linecolor 'gray'