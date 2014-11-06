import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import java.util.List;
import java.util.Arrays;
import java.util.Date;

class Note {
  int id;
  String contents;
  String author;
  Date createdOn;
  List<String> tags;
  String optionalFlag;

  Note(int id, String contents, String author, List<String> tags) {
    this.id = id;
    this.contents = contents;
    this.author = author;
    this.tags = tags;
    this.createdOn = null; //new Date();
    this.optionalFlag = null;
  }

  public String toString() {
    return String.format("id:%d author:%s createdOn:%s", id, author, createdOn);
  }
}

class GsonLib {
  public static void main (String [] args) {
    Gson gson = new GsonBuilder().create();
    
    int[] numbers = {1, 2, 3};
    System.out.println(gson.toJson(numbers));
    
    String[] tagArray = {"bla", "blaaah"};
    List<String> tags = null; // Arrays.asList(tagArray);
    Note note = new Note(12435994, "Blah. Umm...", "John Doe", tags);
    
    String jsonString = gson.toJson(note);
    System.out.println(jsonString);

    Note noteFromJson = gson.fromJson(jsonString, Note.class);
    System.out.println(noteFromJson);
  }
}

// javac GsonLib.java -cp .:lib/gson-2.2.4.jar
// java -cp lib/gson-2.2.4.jar:.  GsonLib
