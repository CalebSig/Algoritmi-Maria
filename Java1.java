//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {

        Masina m1 = new Masina();
        m1.setNumarInmatriculare("BN60ABC");
        System.out.println(m1.getNumarInmatriculare());

        Masina m2 = new Masina("B105AMG","BMW",2012,300);
        System.out.println(m2.getNumarInmatriculare() + " " + m2.getFirma()+ " " + m2.getAnFabricatie() + " " + m2.getHp());

        m1.driveCar();
        m2.driveCar();

    }
}

public class Masina {
    private String numarInmatriculare;
    private String firma;
    private int anFabricatie;
    private Integer hp;

    public Masina(String numarInmatriculare, String firma, int anFabricatie, Integer hp) {
        this.numarInmatriculare = numarInmatriculare;
        this.firma = firma;
        this.anFabricatie = anFabricatie;
        this.hp = hp;
    }
    public Masina() {

    }

    public String getNumarInmatriculare() {
        return numarInmatriculare;
    }

    public void setNumarInmatriculare(String numarInmatriculare) {
        this.numarInmatriculare = numarInmatriculare;
    }

    public String getFirma() {
        return firma;
    }

    public void setFirma(String firma) {
        this.firma = firma;
    }

    public int getAnFabricatie() {
        return anFabricatie;
    }

    public void setAnFabricatie(int anFabricatie) {
        this.anFabricatie = anFabricatie;
    }

    public Integer getHp() {
        return hp;
    }

    public void setHp(Integer hp) {
        this.hp = hp;
    }

    public void driveCar(){
        System.out.println("Driving " + firma + " " + numarInmatriculare + ": Vroooooooom!");
    }

}
