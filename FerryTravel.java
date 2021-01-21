import java.util.concurrent.Semaphore;

class IslandParking {

    public static int N = 70;
    public static int count = 0;
}

public class FerryTravel extends Thread {
    private static int M = 20;
    Semaphore s = new Semaphore(M);

    private String currentLocation;

    public FerryTravel(String location) {
        this.currentLocation = location;
        this.setName(location);
    }

    public void run() {

        if (this.getName().equals("loadOnMainland")) {
            try {
                System.out.println(currentLocation + "Loading the cars into ferry");
                s.acquire();
                for (int i = 0; i < M; i++) {
                    s.acquire();
                    System.out.println(
                            "loaded a car on the Ferry, Available slots on ferry now is: " + s.availablePermits());
                    Thread.sleep(1000);
                    s.release();
                }

            } catch (InterruptedException e) {
                System.out.println(e);
            }

            System.out.println("Ferry is now full and headed to the Island");
            s.release();
        }

        if (this.getName().equals("unloadOnIsland")) {
            try {
                System.out.println(currentLocation + "Unloading the cars on Island");
                s.acquire();
                for (int i = 0; i < M; i++) {
                    s.acquire();
                    IslandParking.count++;
                    System.out.println(
                            "car unloaded from the Ferry, Now the available slots on ferry is:" + s.availablePermits());
                    Thread.sleep(1000);
                    s.release();
                }
            } catch (InterruptedException e) {
                System.out.println(e);
            }
            System.out.println("Done unloading cars at Island Parking");
            s.release();
        }

        if (this.getName().equals("loadOnIsland")) {
            try {
                System.out.println(currentLocation + "Loading cars from Island on Ferry to be sent to mainland");
                s.acquire();
                for (int i = 0; i < 10; i++) {
                    System.out.println("Loaded car on Ferry, Now available slot on ferry is:" + s.availablePermits());
                    IslandParking.count--;
                    Thread.sleep(1000);
                }

            } catch (InterruptedException e) {
                System.out.println(e);
            }
            System.out.println("Done Loading cars, Ferry is now headed to Mainland");
            s.release();
        }

    }

    public static void main(String[] args) {
        final int threadpool = 30;
        FerryTravel thread1 = new FerryTravel("loadOnMainland");
        FerryTravel thread2 = new FerryTravel("unloadOnIsland");
        FerryTravel thread3 = new FerryTravel("loadOnIsland");

        if (IslandParking.count != IslandParking.N && threadpool > 0) {
            thread1.start();
            thread2.start();
            thread3.start();
        }
    }
}