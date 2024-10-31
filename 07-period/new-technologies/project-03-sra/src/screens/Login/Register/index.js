import { Button } from "@/components/Button";
import { Form } from "@/components/Form";
import { Input } from "@/components/Input";
import { useAppNavigation } from "@/hooks/useAppNavigation";
import { LoginLayout } from "@/screens/Login/components/LoginLayout";
import styles from "@/screens/Login/styles";
import { isAllFieldsFilled } from "@/utils/isAllFieldsFilled";
import { useRoute } from "@react-navigation/native";
import { useEffect, useState } from "react";
import { Controller, useForm } from "react-hook-form";
import { Text } from "react-native";

const FORM_FIELDS = ["name", "email"];

export function RegisterScreen() {
  const { params } = useRoute();
  const { values } = params ?? {};

  const [isButtonDisabled, setIsButtonDisabled] = useState(true);
  const { getGoTo } = useAppNavigation();

  const { watch, control, setValue } = useForm();
  watch((values) => {
    setIsButtonDisabled(!isAllFieldsFilled(values ?? {}, FORM_FIELDS));
  });

  useEffect(() => {
    if (values) {
      Object.entries(values).forEach(([key, value]) => {
        setValue(key, value);
      });
    }
  }, []);

  return (
    <LoginLayout title="bem-vindo(a)!!" subtitle="vamos nos conhecer melhor?">
      <Form>
        <Controller
          control={control}
          name="name"
          render={({ field: { value, onChange } }) => (
            <Input label="nome" value={value} onChange={onChange} />
          )}
        />
        <Controller
          control={control}
          name="email"
          render={({ field: { value, onChange } }) => (
            <Input
              type="email"
              label="e-mail"
              value={value}
              onChange={onChange}
            />
          )}
        />
        <Text style={styles.tip}>
          lembre-se de usar seu e-mail com @unesp.br
        </Text>
        <Button
          onPress={getGoTo("RegisterFinal", { backTo: null })}
          disabled={isButtonDisabled}
        >
          continuar
        </Button>
      </Form>
    </LoginLayout>
  );
}
