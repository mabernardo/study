package br.com.versper.patterns;

/**
 * Created by nitewolf on 6/8/17.
 */
public class MuteQuack implements QuackBehavior {
    public void quack() {
        System.out.println("<< Silence >>");
    }
}

