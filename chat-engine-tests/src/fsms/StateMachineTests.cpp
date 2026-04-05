#include <gtest/gtest.h>
#include "fsms/StateMachine.hpp"
#include "states/State.hpp"
#include <stdexcept>

namespace ChatEngine::Tests
{
    class TestStateB : public ChatEngine::State
    {
    public:
        TestStateB(ChatEngine::StateMachine& sm) : State(sm), called(false) {}

        void handle() override
        {
            called = true;
            m_stateMachine.exit();
        }

        bool called;
    };

    class TestStateA : public ChatEngine::State
    {
    public:
        TestStateA(ChatEngine::StateMachine& sm) : State(sm), called(false) {}

        void handle() override
        {
            called = true;
            m_stateMachine.moveToState<TestStateB>();
        }

        bool called;
    };

    TEST(StateMachineTests, addState_ShouldStoreState_WhenValidStateProvided)
    {
        StateMachine sut;

        sut.addState<TestStateA>(sut);

        ASSERT_NO_THROW(sut.getState<TestStateA>());
    }

    TEST(StateMachineTests, getState_ShouldThrow_WhenStateDoesNotExist)
    {
        StateMachine sut;

        ASSERT_THROW(sut.getState<TestStateA>(), std::runtime_error);
    }

    TEST(StateMachineTests, moveToState_ShouldSetCurrentState_WhenStateExists)
    {
        StateMachine sut;

        sut.addState<TestStateA>(sut);

        ASSERT_NO_THROW(sut.moveToState<TestStateA>());
    }

    TEST(StateMachineTests, run_ShouldTransitionBetweenStates_WhenStatesMoveNext)
    {
        StateMachine sut;

        sut.addState<TestStateA>(sut);
        sut.addState<TestStateB>(sut);

        auto stateA = sut.getState<TestStateA>();
        auto stateB = sut.getState<TestStateB>();

        sut.moveToState<TestStateA>();
        sut.run();

        ASSERT_TRUE(stateA->called);
        ASSERT_TRUE(stateB->called);
    }

    TEST(StateMachineTests, exit_ShouldStopExecution_WhenCalledFromState)
    {
        StateMachine sut;

        sut.addState<TestStateB>(sut);

        auto* state = static_cast<TestStateB*>(sut.getState<TestStateB>());

        sut.moveToState<TestStateB>();
        sut.run();

        ASSERT_TRUE(state->called);
    }
}