package br.com.versper.patterns;

import java.util.ArrayList;
import java.util.Observable;

/**
 * Created by nitewolf on 6/14/17.
 */
public class StatisticsDisplay implements Observer, DisplayElement {
    private float average_temperature = 0.0f;
    private float max_temperature = 0.0f;
    private float min_temperature = 0.0f;
    private ArrayList<Float> temperature_history;
    private Subject weatherData;

    public StatisticsDisplay(Subject weatherData) {
        temperature_history = new ArrayList<>();
        this.weatherData = weatherData;
        weatherData.registerObserver(this);
    }

    @Override
    public void update(float temp, float humidity, float pressure) {
        this.temperature_history.add(temp);
        this.average_temperature = (float) temperature_history.stream().mapToDouble(i -> i).average().orElse(0.0);
        this.min_temperature = (float) temperature_history.stream().mapToDouble(i -> i).min().getAsDouble();
        this.max_temperature = (float) temperature_history.stream().mapToDouble(i -> i).max().getAsDouble();
        display();
    }

    @Override
    public void display() {
        System.out.println("Avg/Max/Min temperature = "
                + average_temperature + "/"
                + max_temperature + "/"
                + min_temperature);
    }
}
