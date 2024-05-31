import { StyleSheet } from "react-native";

const ANIMATIONS = {
  opacity: (animation) => ({ opacity: animation }),
  scale: (animation) => ({ transform: [{ scale: animation }] }),
};

export function useAnimations(...animations) {
  const animationsReduced = animations.reduce(
    (acc, item) => ({
      ...acc,
      style: {
        ...acc.style,
        ...ANIMATIONS[item.property](item.animation),
      },
      in: {
        ...acc.in,
        [item.property]: item.in,
      },
      out: {
        ...acc.out,
        [item.property]: item.out,
      },
    }),
    {}
  );

  const onStart = () => {
    Object.values(animationsReduced.in).forEach((func) => {
      func();
    });
  };

  const onEnd = () => {
    Object.values(animationsReduced.out).forEach((func) => {
      func();
    });
  };

  return { animations: animationsReduced.style, onStart, onEnd };
}
