We go to this directory: /home/kern/build2/linux-5.15.7/arch/x86/entry/syscalls/syscall_64.tbl
	and we give entry at 449 to our syscall in the syscall_64.tbl.
	as : 449 common  reader         sys_writer
	and 450 as : 450 common writer		sys_writer
4. We go to this directory: /home/kern/build2/linux-5.15.4/kernel/sys.c
	Add two functions SYSCALL_DEFINE1(reader,long,value): This system call dequeues from the queue enqueued using sys_writer, and prints the random string.
			  SYSCALL_DEFINE1(writer,long ,value):This system call takes 8byte random string from dev/urandom/ and enqueues it in the queue.



We used mutex_lock to lock the critical section so that there will not be
overriding along their data as only one proces would be able to enter that section(Synchronization).
data structure has been used: Queue
logic and implementation:
	The Producer-Consumer problem is a classic problem this is used for multi-process synchronization 
    	i.e. synchronization between more than one processes.
	We created two testing function named as p.c and q.c. 
	In p.c we read random 8-bytes of the device /dev/urandom by opening the file using open("/dev/random", O_RDONLY);
	abd readed this using read(RandomV, buffer, sizeof(buffer)); where buffer is the char of size 8 bytes.
	We are converting this buffer as long. And we are sending this value using syscall
	We used mutex_lock to lock the critical section so that there will not be overriding along their
	data as only one proces would be able to enter that section.



Testing:
	compile: p.c and q.c using make.
	run: p.c and q.c using ./p and ./q respectively.

Expected Output:
	We get enqueued long and ASCII. in the left and dequeued long and ASCII in the right..
	