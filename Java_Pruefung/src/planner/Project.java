package planner;
import java.io.OutputStreamWriter;
import java.io.IOException;
import java.util.Date;
import java.util.ArrayList;
import java.io.BufferedWriter;


public class Project {
    Date startDate;
    Date endDate;
    ArrayList<Task> tasks = new ArrayList<Task>();

    public void setStartDate() {
        startDate = new Date();
    }

    public void setEndDate() {
        endDate = new Date();
    }

    public void printDate() {
        System.out.println("start: " + startDate + "\n end: " + endDate);
    }

    public void addTask(Task t) {
        tasks.add(t);
    }
    /* public void printList(){
        for( Task out : tasks){
            System.out.println(out.toString());
        }
    } */

    public void writer(BufferedWriter w) {
        for (Task t : this.tasks) {
            try {
                w.write(t.description + " ; " + t.duration.toString());
                w.newLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        try {
            w.close();
        } catch (IOException e) {
            e.printStackTrace();
        }


    }




public static void main(String[] args) {
    Project pro = new Project();
    pro.setStartDate();
    pro.setEndDate();
    pro.printDate();
    Task task = new Task("this is gonna fail", 1.0);
    Task task2 = new Task("ok mate", 13.0);
    pro.addTask(task);
    pro.addTask(task2);
    //pro.printList();

    pro.writer(new BufferedWriter(new OutputStreamWriter(System.out)));

}


}