package com.elsys.fitness.employee;

import com.elsys.fitness.Fitness;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.NullAndEmptySource;
import org.junit.jupiter.params.provider.ValueSource;

import static org.junit.jupiter.api.Assertions.*;

class EmployeeTest {
    private Employee employee;

    @BeforeEach
    void setUp() {
        employee = new Employee("asd", "asd", new Fitness(1, "")) {
        };
    }

    @Test
    void setFirstName_givenNotBlankName_expectedSuccess() {
        employee.setFirstName("Ivan");

        assertEquals("Ivan", employee.getFirstName());
    }

    @ParameterizedTest
    @NullAndEmptySource
    @ValueSource(strings = {"  "})
    void setFirstName_givenBlankName_expectedException(String name) {
        assertThrows(IllegalArgumentException.class, () -> {
            employee.setFirstName(name);
        });
    }
}