import { StatusBar } from "expo-status-bar";
import { SafeAreaView } from "react-native";
import * as SplashScreen from "expo-splash-screen";

import { useState } from "react";
import { HeadingText } from "./src/components/ui/HeadingText";
import { useFontsLoad } from "./src/hooks/useFontsLoad";
import styles from "./App.styles";

import { Button } from "./src/components/ui/Button";

import { Game } from "./src/pages/Game";
import { genRandomNumber } from "./src/components/constants/generator";
import { difficulties } from "./src/components/constants/difficulties";

SplashScreen.preventAutoHideAsync();

let timeout;

export default function App() {
  const [difficulty, setDifficulty] = useState("easy");
  const [hidden, setHidden] = useState(false);
  const [numbers, setNumbers] = useState([]);
  const [index, setIndex] = useState(0);
  const [level, setLevel] = useState(0);
  const { isLoading, onLayoutRootView } = useFontsLoad();

  if (isLoading) {
    return null;
  }

  const initiateTimer = () => {
    setHidden(false);
    clearTimeout(timeout);

    timeout = setTimeout(() => {
      setHidden(true);
    }, difficulties[difficulty].timeout);
  };

  return (
    <SafeAreaView style={styles.container} onLayout={onLayoutRootView}>
      <HeadingText style={{ paddingHorizontal: 20 }}>Memory Game</HeadingText>
      {level !== 0 ? (
        <Game
          numbers={numbers}
          setNumbers={setNumbers}
          index={index}
          setIndex={setIndex}
          level={level}
          setLevel={setLevel}
          hidden={hidden}
          setHidden={setHidden}
          initiateTimer={initiateTimer}
        />
      ) : (
        <>
          <Button
            onPress={() => {
              // Initialize with 3 random numbers
              setNumbers(() =>
                [genRandomNumber(), genRandomNumber(), genRandomNumber()].map(
                  (number) => ({ number, typed: "" }),
                ),
              );

              setLevel(1);
              initiateTimer();
            }}
          >
            Start game
          </Button>
          <Button
            style={{ marginTop: 10 }}
            onPress={() => {
              setDifficulty((prev) => {
                if (prev === "easy") {
                  return "normal";
                }

                if (prev === "normal") {
                  return "hard";
                }

                return "easy";
              });
            }}
          >
            Difficulty: {difficulties[difficulty].label}
          </Button>
        </>
      )}
      <StatusBar style="auto" />
    </SafeAreaView>
  );
}
