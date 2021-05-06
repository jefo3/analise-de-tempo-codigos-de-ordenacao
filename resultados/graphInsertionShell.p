#Jeferson Gonçalves Noronha Soriano - 471110


# gnuplot file
# generates the graph for cocktail sort and Bubblesort

set term png                        # will produce .png output
set output "graficoComparacaoIS.png"  # output to any filename.png you want
set grid                            # grid background
set title 'Insertion x Shell'       # plot title
set xlabel 'Tamanho do Vetor'       # x-axis label
set ylabel 'Microssegundos'          # y-axis label
set multiplot                       # multiplot mode (prompt changes to 'multiplot')

# plot the graphic
plot 'resultadoInsertion.txt' with linespoints title 'Insertion', 'resultadoShell.txt' with linespoints title 'Shell'

unset multiplot                     # exit multiplot mode (prompt changes back to 'gnuplot')