import { Alert, View } from "react-native";
import { useState } from "react";
import { CarouselInput } from "../../components/CarouselInput";
import { TouchableKeyboard } from "../../components/TouchableKeyboard";
import { BodyText } from "../../components/ui/BodyText";
import { Button } from "../../components/ui/Button";
import { genRandomNumber } from "../../components/constants/generator";

export function Game({
  numbers,
  setNumbers,
  index,
  setIndex,
  level,
  setLevel,
  hidden,
  setHidden,
  initiateTimer,
}) {
  const [showResults, setShowResults] = useState(false);
  const userGuessed = numbers.every((item) => item.number === item.typed);

  return (
    <View style={{ alignItems: "center" }}>
      <BodyText>{`Score: ${level - 1}`}</BodyText>
      <CarouselInput
        hidden={hidden}
        numbers={numbers}
        showResults={showResults}
      />
      <TouchableKeyboard
        currentIndex={index}
        setCurrentIndex={setIndex}
        setNumbers={setNumbers}
        showResults={showResults}
      />
      <View style={{ width: 180, marginTop: 20 }}>
        {!showResults ? (
          <Button
            disabled={index !== numbers.length}
            onPress={() => {
              setShowResults(true);

              if (!userGuessed) {
                Alert.alert(
                  "You missed!",
                  `The correct sequence was: ${numbers.map(({ number }) => number).join(" ")}\nYour score was: ${level - 1}\nTry again!`,
                );
              }
            }}
          >
            Submit
          </Button>
        ) : (
          showResults &&
          userGuessed && (
            <Button
              onPress={() => {
                setNumbers((prev) =>
                  prev
                    .concat({ number: genRandomNumber() })
                    .map((item) => ({ ...item, typed: "" })),
                );

                setLevel((prev) => prev + 1);
                setIndex(0);
                setShowResults(false);
                setHidden(false);

                initiateTimer();
              }}
            >
              Next
            </Button>
          )
        )}
        <Button
          style={{ marginTop: 10 }}
          onPress={() => {
            setIndex(0);
            setLevel(0);
            setNumbers([]);
            setHidden(false);
            setShowResults(false);
          }}
        >
          {showResults ? "Restart" : "Quit"}
        </Button>
      </View>
    </View>
  );
}
