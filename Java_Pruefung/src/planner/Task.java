package planner;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.sql.Time;

public class Task {
    String description;
    Double duration;
    public Task(String s, double t){
        if(t <= 0){
            throw new IllegalArgumentException("duration must be > 0");
        }
        description = s;
        duration = t;


    }
    @Override
    public String toString() {
        //return super.toString();
        return description+" ; "+duration;
    }


}
