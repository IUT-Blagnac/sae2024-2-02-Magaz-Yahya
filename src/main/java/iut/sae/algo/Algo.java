package iut.sae.algo;


public class Algo{
    public static String RLE(String in) {
        String rle = "";
        int count = 1;
        for (int i = 0; i < in.length(); i++) {
            if (i + 1 < in.length() && in.charAt(i) == in.charAt(i + 1) && count!=9) {
                count++;
            } else {
                rle += count + "" + in.charAt(i);
                count = 1;
            }
        }
        return rle;
    }
    

    public static String RLE(String in, int iteration) throws AlgoException{
        String resultat=in;
        for(int i=0;i<iteration;i++){
            resultat=RLE(in);
            in=resultat;

        }
        return resultat;
    }

    public static String unRLE(String in) throws AlgoException {

    }

    public static String unRLE(String in, int iteration) throws AlgoException{
        // Provide your algo here
        return "NotYetImplemented";

    }
}

