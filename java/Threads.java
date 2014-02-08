class TestThread implements Runnable {
	public void run() {
		String threadName = Thread.currentThread().getName();
		long threadID = Thread.currentThread().getId();

		System.out.println(threadName + " : " + threadID + " : Begin ...");
		try {
			Thread.sleep((long)(Math.random() * 2000));
			System.out.println(threadName + " : " + threadID + " : hello world !!!");
			Thread.sleep((long)(Math.random() * 2000));
		}
		catch(Exception e) {
			e.printStackTrace();
		}
		System.out.println(threadName + " : " + threadID + " : End.");
	}
}

class Threads {
	public static void main(String[] args) {
		Thread[] threads = new Thread[64];
		for(int i = 0; i < threads.length; ++i) {
			threads[i] = new Thread(new TestThread());
			threads[i].start();
		}
	}
}

