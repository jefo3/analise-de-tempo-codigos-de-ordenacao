#Jeferson Gonçalves Noronha Soriano - 471110

# gnuplot file
# generates the graph for cocktail sort and Bubblesort

set term png                        # will produce .png output
set output "graficoComparacaoMQ.png"  # output to any filename.png you want
set grid                            # grid background
set title 'Merge x Quick'       # plot title
set xlabel 'Tamanho do Vetor'       # x-axis label
set ylabel 'Microssegundos'          # y-axis label
set multiplot                       # multiplot mode (prompt changes to 'multiplot')

# plot the graphic
plot 'resultadoMerge.txt' with linespoints title 'Merge', 'resultadoQuick.txt' with linespoints title 'Quick'

unset multiplot                     # exit multiplot mode (prompt changes back to 'gnuplot')
