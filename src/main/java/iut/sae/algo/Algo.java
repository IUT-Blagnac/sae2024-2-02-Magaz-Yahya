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
        String rle = "";
        for(int i=0;i<=iteration;i++){
            int count = 1;
            for (int j = 0; j < in.length(); j++) {
                if (j + 1 < in.length() && in.charAt(j) == in.charAt(j + 1)) {
                    count++;
                } else {
                    rle += count + "" + in.charAt(j);
                    count = 1;
                }
                in=rle;
            }
            
        }
        return rle;
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

