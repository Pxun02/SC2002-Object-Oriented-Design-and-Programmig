public class SalePerson implements Comparable{
    private String firstName;
    private String lastName;
    private int totalSales;

    public SalePerson(String firstName, String lastName, int totalSales){
        this.firstName = firstName;
        this.lastName = lastName;
        this.totalSales = totalSales;
    }

    public String toString(){
        return lastName + " ," + firstName + " :" + totalSales;
    }

    public boolean equals(Object o){
        if(((SalePerson) o).getFirstName() == getFirstName()&&
        ((SalePerson) o).getLastName() == getLastName()){
            return true;
        }
        return false;
    }

    public int compareTo(Object o){
        SalePerson sp = (SalePerson) o;
        if(this.totalSales > sp.getTotalSales())
        {
            return 1;
        }else if(this.totalSales < sp.getTotalSales()){
            return -1;
        }else{
            return sp.getLastName().compareTo(this.lastName);
        }
    }

    public String getFirstName(){
        return firstName;
    }

    public String getLastName(){
        return lastName;
    }

    public int getTotalSales(){
        return totalSales;
    }
}