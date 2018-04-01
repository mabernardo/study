package br.com.versper.patterns;

/**
 * Created by nitewolf on 6/14/17.
 */
public interface Subject {
    void registerObserver(Observer o);
    void removeObserver(Observer o);
    void notifyObservers();
}
