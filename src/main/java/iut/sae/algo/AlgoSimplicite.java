package iut.sae.algo;


public class AlgoSimplicite{
    public static String RLE(String in) {
        String rle = "";
        int compteur = 1;
        for (int i = 0; i < in.length(); i++) {
            if (i+1 < in.length() && in.charAt(i) == in.charAt(i+1) && compteur!=9) {
                compteur++;
            } else {
                rle += compteur + "" + in.charAt(i);//Transforme le compteur et le caractère en String
                compteur = 1;
            }
        }
        return rle;
    }
    

    public static String RLE(String in, int iteration) throws AlgoException{
        String resultat=in;
        for(int i=0;i<iteration;i++){
            resultat=RLE(resultat);
        }
        return resultat;
    }

    public static String unRLE(String in) throws AlgoException {
        String resultat = "";
        int tailleIn = in.length();
        for (int i = 0; i < tailleIn; i++) {
            int nbBoucle = in.charAt(i) - '0';//Transforme un caractère en entier.
            i++;
            char caractere = in.charAt(i);//Récupère le caractère à l'indice i de la chaîne de caractères.
            for (int j = 0; j < nbBoucle; j++) {
                resultat += caractere;
            }
        }
        
        return resultat;
    }
    
    
    public static String unRLE(String in, int iteration) throws AlgoException{
        String resultat=in;
        for(int i=0;i<iteration;i++){
            resultat=unRLE(resultat);

        }
        return resultat; 

    }
}

