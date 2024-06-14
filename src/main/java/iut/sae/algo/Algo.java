package iut.sae.algo;


public class Algo{
    public static String RLE(String in) {
        String rle = "";
        int compteur = 1;
        for (int i = 0; i < in.length(); i++) {
            if (i+1 < in.length() && in.charAt(i) == in.charAt(i+1) && compteur!=9) {
                compteur++;
            } else {
                rle += compteur + "" + in.charAt(i);
                compteur = 1;
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
        String resultat = "";
        int tailleIn = in.length();
        for (int i = 0; i < tailleIn; i++) {
            int nbBoucle = Integer.parseInt("" + in.charAt(i));
            i++;
            char caractere = in.charAt(i);
            for (int j = 0; j < nbBoucle; j++) {
                resultat += caractere;
            }
        }
        
        return resultat;
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

