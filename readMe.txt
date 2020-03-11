实现简单的信号量

类semaphore：资源数count、mutex锁mtx、条件变量con_var

主要功能：wait()、singal()

信号量相当于是一个资源计数器。当消费资源时，使用wait()等信号，使count减1，如果count小于0，则进程挂起或睡眠，当count小于0时，count的绝对值就是进程挂起或睡眠的数目；当生产资源时，使用signal()给信号，如果count小于0，则唤醒进程，并使count加1
