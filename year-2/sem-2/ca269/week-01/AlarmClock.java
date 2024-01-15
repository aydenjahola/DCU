import java.util.Scanner;

public class AlarmClock {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Get the alarm time
        int alarmHour = scanner.nextInt();
        int alarmMinute = scanner.nextInt();

        int falseAlarms = 0;

        // Keep asking for current time until it is later than the alarm time
        while (true) {
            int currentHour = scanner.nextInt();
            int currentMinute = scanner.nextInt();

            if (currentHour > alarmHour || (currentHour == alarmHour && currentMinute >= alarmMinute)) {
                break;
            }

            falseAlarms++;
        }

        System.out.println("false alarms: " + falseAlarms);
    }
}
