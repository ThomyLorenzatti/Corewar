sti r1, %:live, %1
.name "aaa"
.comment "I'M ALIIIIVE"
					
			
				
sti r1, %:live, %1
l2:		sti r1, %:live, %1
		and r1, %0, r1

live:	live %1
		zjmp %:live
