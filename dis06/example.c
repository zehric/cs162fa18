struct list brace_yourself;
struct lock midterm;
struct lock is_coming;
void tyrion(){
	thread_set_priority(12);
	lock_acquire(&midterm);
	lock_release(&midterm);
	thread_exit();
}
void ned(){
	lock_acquire(&midterm);
	lock_acquire(&is_coming);
	list_remove(list_head(brace_yourself));
	lock_release(&midterm);
	lock_release(&is_coming);
	thread_exit();
}
void gandalf(){
	lock_acquire(&is_coming);
	thread_set_priority(3);
	while (thread_get_priority() < 11) {
		printf("YOU .. SHALL NOT .. PAAASS!!!!!!");
		timer_sleep(20);
	}
	lock_release(&is_coming);
	thread_exit();
}
