#Jeferson Gonçalves Noronha Soriano - 471110

# gnuplot file
# generates the graph for cocktail sort test

set term png                        # will produce .png output
set output "graficoQuick.png"    # output to any filename.png you want
set grid                            # grid background
set title 'Quick Sort'           # plot title
set xlabel 'Tamanho do Vetor'       # x-axis label
set ylabel 'Microsegundos'          # y-axis label

# plot the graphic
plot 'resultadoQuick.txt' with linespoints title 'Quick'
