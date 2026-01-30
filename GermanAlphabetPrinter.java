public class GermanAlphabetPrinter {
    public static void main(String[] args) {
        String germanAlphabet = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZzÄäÖöÜüß";
        for (char c : germanAlphabet.toCharArray()) {
            System.out.print(c + " ");
        }
    }
}