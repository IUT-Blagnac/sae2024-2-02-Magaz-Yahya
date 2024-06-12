package iut.sae.algo;


public class Algo{
    public static String RLE(String in) {
        String rle = "";
        int count = 1;
        for (int i = 0; i < in.length(); i++) {
            if (i + 1 < in.length() && in.charAt(i) == in.charAt(i + 1)) {
                count++;
            } else {
                rle += count + "" + in.charAt(i);
                count = 1;
            }
        }
        return rle;
    }
    

    public static String RLE(String in, int iteration) throws AlgoException{
        // Provide your algo here
        return "NotYetImplemented";
    }

    public static String unRLE(String in) throws AlgoException{
        // Provide your algo here
        return "NotYetImplemented";

    }

    public static String unRLE(String in, int iteration) throws AlgoException{
        // Provide your algo here
        return "NotYetImplemented";

    }
}

