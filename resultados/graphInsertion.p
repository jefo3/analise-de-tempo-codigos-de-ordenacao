#Jeferson Gonçalves Noronha Soriano - 471110

# gnuplot file
# generates the graph for bublesort test

set term png                        # will produce .png output
set output "graficoInsertion.png"    # output to any filename.png you want
set grid                            # grid background
set title 'Insection Sort'           # plot title
set xlabel 'Tamanho do Vetor'       # x-axis label
set ylabel 'Microsegundos'          # y-axis label

# plot the graphic
plot 'resultadoInsertion.txt' with linespoints  title 'Insertion'