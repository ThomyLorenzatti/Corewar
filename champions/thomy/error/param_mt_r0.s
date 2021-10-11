.name "zork"
.comment "just a basic living prog"

l2:
		sti r0,%:live,%1
		and r0,%0,r1
live:   live %1
		zjmp %:live
