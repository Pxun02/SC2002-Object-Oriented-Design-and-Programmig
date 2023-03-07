import java.util.Scanner;

class PlaneSeat {
    private int seatId;
    private boolean assigned;
    private int customerId;
    public PlaneSeat(int seat_id) {
        this.seatId = seat_id;
        this.assigned = false;
        this.customerId = -1;
    }
    public int getSeatId() {
        return seatId;
    }
    public int getCustomerId() {
        return customerId;
    }
    public boolean isOccupied() {
        return assigned;
    }
    public void assign(int cust_id) {
        customerId = cust_id;
        assigned = true;
    }
    public void unAssign() {
        customerId = -1;
        assigned = false;
    }
}

class Plane {
    private PlaneSeat[] seat = new PlaneSeat[12];
    private int numEmptySeat;
    public Plane(){
        for (int i=0;i<12;i++){
            seat[i] = new PlaneSeat(i+1);
        }
        numEmptySeat = 12;
    }
    private PlaneSeat[] sortSeats() {
        int i = 0;
        int cur_min;
        int seat_id = 0;
        PlaneSeat[] tmp = new PlaneSeat[12-numEmptySeat];
        for(int j=0;j<12-numEmptySeat;j++){
            cur_min = -1;
            for(i=0;i<12;i++){
                if(cur_min==-1 && seat[i].getCustomerId()>0 ){
                    cur_min = seat[i].getCustomerId();
                    seat_id = i;

                }else if(j==0){
                    if(seat[i].getCustomerId()>0  && seat[i].getCustomerId() < cur_min){
                        cur_min = seat[i].getCustomerId();
                        seat_id = i;
                    }
                }else{
                    if(seat[i].getCustomerId() < cur_min && tmp[j-1].getCustomerId() < seat[i].getCustomerId()){
                        cur_min = seat[i].getCustomerId();
                        seat_id = i;
                    }
                }
            }tmp[j] = new PlaneSeat(seat_id+1);
            tmp[j].assign(cur_min);
        }
        return tmp;
    }

    public void showNumEmptySeats(){
        System.out.printf("There are %d empty seats%n", numEmptySeat);
    }

    public void showEmptySeats() {
        System.out.println("The following seats are empty:");
        for(int i=0;i<12;i++){
            if(seat[i].isOccupied()==false)
                System.out.printf("SeatID %d%n", i+1);
        }
    }

    public void showAssignedSeats(boolean bySeatId) {
        System.out.println("The seat assignments are as follow:");
        if(bySeatId){
            for(int i=0;i<12;i++){
                if(seat[i].isOccupied()==true)
                    System.out.printf("SeatID %d assigned to CustomerID %d%n", i+1, seat[i].getCustomerId());
            }       
        }else{
            PlaneSeat[] sorted = new PlaneSeat[12-numEmptySeat];
            sorted = sortSeats();
            for(int i=0;i<12-numEmptySeat;i++){
                System.out.printf("SeatID %d assigned to CustomerID %d%n", sorted[i].getSeatId(), sorted[i].getCustomerId());
            }
        }
    }

    public void assignSeat(int seatId, int cust_id) {
        if(seat[seatId-1].isOccupied()){
            System.out.println("Seat already assigned to a customer.");
        }else{
            seat[seatId-1].assign(cust_id);
            numEmptySeat--;
            System.out.println("Seat Assigned!");
        }
    }
    
    public void unAssignSeat(int seatId) {
        if(seat[seatId-1].isOccupied()){
            seat[seatId-1].unAssign();
            numEmptySeat++;
            System.out.println("Seat Unassigned!");
        }else{
            System.out.println("Seat already unassigned.");   
        }
    }
}


public class PlaneApp{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Plane pl = new Plane();
        boolean loop = true;

        System.out.println("(1) Show number of empty seats");
        System.out.println("(2) Show the list of empty seats");
        System.out.println("(3) Show the list of seat assignments by seat ID");
        System.out.println("(4) Show the list of seat assignments by customer ID");
        System.out.println("(5) Assign a customer to a seat");
        System.out.println("(6) Remove a seat assignment");
        System.out.println("(7) Exit");
        try {
            while(loop) {
                System.out.printf("%n  Enter the number of your choice: ");
                int c = sc.nextInt();
                switch(c){
                    case(1):
                        pl.showNumEmptySeats(); break;
                    case(2):
                        pl.showEmptySeats(); break;
                    case(3):
                        pl.showAssignedSeats(true); break;
                    case(4):
                        pl.showAssignedSeats(false); break;
                    case(5):
                        System.out.println("Assigning Seat ..");
                        System.out.printf("  Please enter SeatID: ");
                        int seat_id = sc.nextInt();
                        System.out.printf("  Please enter Customer ID: ");
                        int cust_id = sc.nextInt();
                        pl.assignSeat(seat_id, cust_id);
                        break;
                    case(6):
                        System.out.printf("  Enter SeatID to unassign customer from: ");
                        int unas = sc.nextInt();
                        pl.unAssignSeat(unas);
                        break;
                    default:
                        loop = false; break;
                }
            }
        }finally{
            if(sc!=null)    sc.close();
        }
    }
}
