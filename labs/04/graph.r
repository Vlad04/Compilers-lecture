# Define 2 vectors
lex_compiler <- c(3.114, 0.663, 1.497)
c_compiler <- c(3.755, 0.446, 1.786)


g_range <- range(0, lex_compiler, 4)

plot(lex_compiler, type="o", col="blue", ylim=g_range, 
   axes=FALSE, ann=FALSE)

# Make x axis using Mon-Fri labels
axis(1, at=1:3, lab=c("Real","User","Sys"))

# Make y axis with horizontal labels that display ticks at 
# every 4 marks. 4*0:g_range[2] is equivalent to c(0,4,8,12).
axis(2, las=1, at=4*0:g_range[2])

# Create box around plot
box()

# Graph c_compiler with red dashed line and square points
lines(c_compiler, type="o", pch=22, lty=2, col="red")

# Create a title with a red, bold/italic font
title(main="lexical_analyzer", col.main="red", font.main=4)

# Label the x and y axes with dark green text
title(xlab="Time", col.lab=rgb(0,0.5,0))
title(ylab="", col.lab=rgb(0,0.5,0))

# Create a legend at (1, g_range[2]) that is slightly smaller 
# (cex) and uses the same line colors and points used by 
# the actual plots 
legend(1, g_range[2], c("lex_compiler","c_compiler"), cex=0.8, 
   col=c("blue","red"), pch=21:22, lty=1:2);
