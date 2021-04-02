package com.elsys.fitness;

import com.elsys.fitness.employee.Employee;
import com.elsys.fitness.employee.EmployeeType;
import com.elsys.fitness.exceptions.FitnessException;
import com.elsys.fitness.exceptions.TrainingException;
import com.elsys.fitness.trainers.GroupTrainer;
import com.elsys.fitness.trainers.PersonalTrainer;
import com.elsys.fitness.trainers.Trainer;
import com.elsys.fitness.training.TrainingType;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.util.Collections;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class FitnessTest {

    private Fitness fitness;

    @BeforeEach
    void setUp() {
        fitness = new Fitness(1, "fitness");
        fitness.hireEmployee("Ivan", "Ivanov", EmployeeType.PERSONAL_TRAINER);
        fitness.hireEmployee("Ivanka", "Ivanova", EmployeeType.REGISTER_EMPLOYEE);
    }

    @Test
    void performTraining_givenCustomerDoesNotExist_expectedFitnessException() throws FitnessException, TrainingException {
        Card card = new Card();
        Customer customer = new Customer("Test", "Test", card);

        assertThrows(FitnessException.class, () -> {
            fitness.performTraining("test", TrainingType.PERSONAL_TRAINING, Collections.singletonList(customer));
        });
    }

    @Test
    void performTraining_givenPersonalTraining_expectedPersonalTrainerPerformedTraining() throws FitnessException, TrainingException {
        //Given - prerequisites
        Customer customer = fitness.registerCustomer("Pesho", "Petrov");

        //When - action/method call
        fitness.performTraining("training", TrainingType.PERSONAL_TRAINING, Collections.singletonList(customer));

        //Then - result validation
        Trainer trainer = fitness.getOrderedFitnessTrainers().get(0);
        assertTrue(trainer instanceof PersonalTrainer);
        assertEquals(1, trainer.getTrainedCustomers());
    }
}