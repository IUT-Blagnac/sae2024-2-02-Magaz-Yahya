package iut.sae.algo;


public class AlgoSobriété{
    public static String RLE(String in) {
    StringBuilder rle = new StringBuilder();
    int count = 1;
    for (int i = 0; i < in.length(); i++) {
        if (i + 1 < in.length() && in.charAt(i) == in.charAt(i + 1) && count < 9) {
            count++;
        } else {
            rle.append(count).append(in.charAt(i));
            count = 1;
        }
    }

    return rle.toString();
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
        StringBuilder resultat = new StringBuilder();
        int tailleIn = in.length();
        int nbBoucle;
        for (int i = 0; i < tailleIn; i++) {
            nbBoucle = Integer.parseInt("" + in.charAt(i));
            i++;
            char caractere = in.charAt(i);
            for (int j = 0; j < nbBoucle; j++) {
                resultat.append(caractere);
            }
        }
        
        return resultat.toString();
    }
    
    
    public static String unRLE(String in, int iteration) throws AlgoException{
        String resultat=in;
        for(int i=0;i<iteration;i++){
            resultat=unRLE(in);
            in=resultat;

        }
        return resultat; 

    }
}

