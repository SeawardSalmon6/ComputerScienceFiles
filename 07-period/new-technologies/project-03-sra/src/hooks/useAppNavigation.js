import { useNavigation } from "@react-navigation/native";

export function useAppNavigation() {
  const navigation = useNavigation();

  const goTo = (path, ...params) => {
    navigation.navigate(path, ...params);
  };

  const goBack = () => {
    if (navigation.canGoBack()) {
      navigation.goBack();
    }
  };

  const getGoBack = () => {
    return goBack(null);
  };

  const getGoTo = (path, ...params) => {
    return () => {
      goTo(path, ...params);
    };
  };

  return {
    goTo,
    goBack,
    getGoTo,
    getGoBack,
  };
}
