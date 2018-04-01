package br.com.versper.patterns;

/**
 * Created by nitewolf on 6/8/17.
 */
public class FlyNoWay implements FlyBehavior {
    public void fly() {
        System.out.println("I can't fly");
    }
}
